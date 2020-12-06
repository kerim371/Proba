/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// FooBar Widgets includes
#include "qSlicerKKKFooBarWidget.h"
#include "ui_qSlicerKKKFooBarWidget.h"

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_KKK
class qSlicerKKKFooBarWidgetPrivate
  : public Ui_qSlicerKKKFooBarWidget
{
  Q_DECLARE_PUBLIC(qSlicerKKKFooBarWidget);
protected:
  qSlicerKKKFooBarWidget* const q_ptr;

public:
  qSlicerKKKFooBarWidgetPrivate(
    qSlicerKKKFooBarWidget& object);
  virtual void setupUi(qSlicerKKKFooBarWidget*);
};

// --------------------------------------------------------------------------
qSlicerKKKFooBarWidgetPrivate
::qSlicerKKKFooBarWidgetPrivate(
  qSlicerKKKFooBarWidget& object)
  : q_ptr(&object)
{
}

// --------------------------------------------------------------------------
void qSlicerKKKFooBarWidgetPrivate
::setupUi(qSlicerKKKFooBarWidget* widget)
{
  this->Ui_qSlicerKKKFooBarWidget::setupUi(widget);
}

//-----------------------------------------------------------------------------
// qSlicerKKKFooBarWidget methods

//-----------------------------------------------------------------------------
qSlicerKKKFooBarWidget
::qSlicerKKKFooBarWidget(QWidget* parentWidget)
  : Superclass( parentWidget )
  , d_ptr( new qSlicerKKKFooBarWidgetPrivate(*this) )
{
  Q_D(qSlicerKKKFooBarWidget);
  d->setupUi(this);
}

//-----------------------------------------------------------------------------
qSlicerKKKFooBarWidget
::~qSlicerKKKFooBarWidget()
{
}
