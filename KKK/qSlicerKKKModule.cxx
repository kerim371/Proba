/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// KKK Logic includes
#include <vtkSlicerKKKLogic.h>

// KKK includes
#include "qSlicerKKKModule.h"
#include "qSlicerKKKModuleWidget.h"

#include "hdf5.h"
#include <stdio.h>
#include <stdlib.h>

#define FILE            "h5ex_d_compact.h5"
#define DATASET         "DS1"
#define DIM0            4
#define DIM1            7


//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerKKKModulePrivate
{
public:
  qSlicerKKKModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerKKKModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerKKKModulePrivate::qSlicerKKKModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerKKKModule methods

//-----------------------------------------------------------------------------
qSlicerKKKModule::qSlicerKKKModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerKKKModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerKKKModule::~qSlicerKKKModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerKKKModule::helpText() const
{
  return "This is a loadable module that can be bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerKKKModule::acknowledgementText() const
{
  return "This work was partially funded by NIH grant NXNNXXNNNNNN-NNXN";
}

//-----------------------------------------------------------------------------
QStringList qSlicerKKKModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("John Doe (AnyWare Corp.)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerKKKModule::icon() const
{
  return QIcon(":/Icons/KKK.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerKKKModule::categories() const
{
  return QStringList() << "Examples";
}

//-----------------------------------------------------------------------------
QStringList qSlicerKKKModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerKKKModule::setup()
{
  this->Superclass::setup();

      hid_t       file, space, dset, dcpl;    /* Handles */
    herr_t      status;
    H5D_layout_t    layout;
    hsize_t     dims[2] = {DIM0, DIM1};
    int         wdata[DIM0][DIM1],          /* Write buffer */
                rdata[DIM0][DIM1],          /* Read buffer */
                i, j;

    /*
     * Initialize data.
     */
    for (i=0; i<DIM0; i++)
        for (j=0; j<DIM1; j++)
            wdata[i][j] = i * j - j;

    /*
     * Create a new file using the default properties.
     */
    file = H5Fcreate (FILE, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

    /*
     * Create dataspace.  Setting maximum size to NULL sets the maximum
     * size to be the current size.
     */
    space = H5Screate_simple (2, dims, NULL);

    /*
     * Create the dataset creation property list, set the layout to
     * compact.
     */
    dcpl = H5Pcreate (H5P_DATASET_CREATE);
    status = H5Pset_layout (dcpl, H5D_COMPACT);

    /*
     * Create the dataset.  We will use all default properties for this
     * example.
     */
    dset = H5Dcreate (file, DATASET, H5T_STD_I32LE, space, H5P_DEFAULT, dcpl,
                H5P_DEFAULT);

    /*
     * Write the data to the dataset.
     */
    status = H5Dwrite (dset, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT,
                wdata[0]);

    /*
     * Close and release resources.
     */
    status = H5Pclose (dcpl);
    status = H5Dclose (dset);
    status = H5Sclose (space);
    status = H5Fclose (file);


    /*
     * Now we begin the read section of this example.
     */

    /*
     * Open file and dataset using the default properties.
     */
    file = H5Fopen (FILE, H5F_ACC_RDONLY, H5P_DEFAULT);
    dset = H5Dopen (file, DATASET, H5P_DEFAULT);

    /*
     * Retrieve the dataset creation property list, and print the
     * storage layout.
     */
    dcpl = H5Dget_create_plist (dset);
    layout = H5Pget_layout (dcpl);
    printf ("Storage layout for %s is: ", DATASET);
    switch (layout) {
        case H5D_COMPACT:
            printf ("H5D_COMPACT\n");
            break;
        case H5D_CONTIGUOUS:
            printf ("H5D_CONTIGUOUS\n");
            break;
        case H5D_CHUNKED:
            printf ("H5D_CHUNKED\n");
            break;
        case H5D_VIRTUAL:
            printf ("H5D_VIRTUAL\n");
            break;
        case H5D_LAYOUT_ERROR:
        case H5D_NLAYOUTS:
            printf ("H5D_LAYOUT_ERROR\n");
    }

    /*
     * Read the data using the default properties.
     */
    status = H5Dread (dset, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT,
                rdata[0]);

    /*
     * Output the data to the screen.
     */
    printf ("%s:\n", DATASET);
    for (i=0; i<DIM0; i++) {
        printf (" [");
        for (j=0; j<DIM1; j++)
            printf (" %3d", rdata[i][j]);
        printf ("]\n");
    }

    /*
     * Close and release resources.
     */
    status = H5Pclose (dcpl);
    status = H5Dclose (dset);
    status = H5Fclose (file);
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerKKKModule
::createWidgetRepresentation()
{
  return new qSlicerKKKModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerKKKModule::createLogic()
{
  return vtkSlicerKKKLogic::New();
}
