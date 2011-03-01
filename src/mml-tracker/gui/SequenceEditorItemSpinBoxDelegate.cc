#include <QSpinBox>

#include "SequenceEditorItemSpinBoxDelegate.h"

SequenceEditorItemSpinBoxDelegate::SequenceEditorItemSpinBoxDelegate(
  QObject* parent)
  : QStyledItemDelegate(parent) {

}

// Creates the editor widget used to edit the item at the given index
QWidget* SequenceEditorItemSpinBoxDelegate::createEditor(
  QWidget *parent, const QStyleOptionViewItem &option,
  const QModelIndex &index) const {

  QSpinBox* editor = new QSpinBox(parent);
  // FIXME: these values should be sensible given the patterns currently
  // installed
  editor->setMinimum(0);
  editor->setMaximum(100);

  return editor;
}

// Called when an editor is created to initialize it with data from the model
void SequenceEditorItemSpinBoxDelegate::setEditorData(
  QWidget* editor, const QModelIndex& index) const {

  int value = index.model()->data(index, Qt::EditRole).toInt();
  QSpinBox* spinBox = static_cast<QSpinBox*>(editor);

  spinBox->setValue(value);
}

// Called when editing is finished to commit data from the editor to the model
void SequenceEditorItemSpinBoxDelegate::setModelData(
  QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const {

  QSpinBox* spinBox = static_cast<QSpinBox*>(editor);

  // Interprets the data in the spinbox. If the value has changed since last
  // interpretation it will emit signals.
  spinBox->interpretText();

  int value = spinBox->value();

  model->setData(index, value, Qt::EditRole);
}

void SequenceEditorItemSpinBoxDelegate::updateEditorGeometry(
  QWidget* editor, const QStyleOptionViewItem& option,
  const QModelIndex& index) const {

  editor->setGeometry(option.rect);
}
