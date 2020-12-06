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
