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

// Qt includes
#include <QDebug>

// Slicer includes
#include "qSlicerKKKModuleWidget.h"
#include "ui_qSlicerKKKModuleWidget.h"

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerKKKModuleWidgetPrivate: public Ui_qSlicerKKKModuleWidget
{
public:
  qSlicerKKKModuleWidgetPrivate();
};

//-----------------------------------------------------------------------------
// qSlicerKKKModuleWidgetPrivate methods

//-----------------------------------------------------------------------------
qSlicerKKKModuleWidgetPrivate::qSlicerKKKModuleWidgetPrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerKKKModuleWidget methods

//-----------------------------------------------------------------------------
qSlicerKKKModuleWidget::qSlicerKKKModuleWidget(QWidget* _parent)
  : Superclass( _parent )
  , d_ptr( new qSlicerKKKModuleWidgetPrivate )
{
}

//-----------------------------------------------------------------------------
qSlicerKKKModuleWidget::~qSlicerKKKModuleWidget()
{
}

//-----------------------------------------------------------------------------
void qSlicerKKKModuleWidget::setup()
{
  Q_D(qSlicerKKKModuleWidget);
  d->setupUi(this);
  this->Superclass::setup();
}
