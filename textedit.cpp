#include "textedit.h"

TextEdit::TextEdit(QWidget *parent) : QTextEdit(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
}
