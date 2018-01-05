/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

#ifndef CO_TUI_COMBO_BOX_H
#define CO_TUI_COMBO_BOX_H

#include "TUIElement.h"

#include <QObject>

class QLabel;
class QComboBox;

/** Basic Container
 * This class provides basic functionality and a
 * common interface to all Container elements.<BR>
 * The functionality implemented in this class represents a container
 * which arranges its children on top of each other.
 */
class TUIComboBox : public QObject, public TUIElement
{
    Q_OBJECT

public:
    TUIComboBox(int id, int type, QWidget *w, int parent, QString name);
    virtual ~TUIComboBox();
    virtual void setValue(int type, covise::TokenBuffer &) override;
    void setLabel(QString textl) override;

    /// get the Element's classname
    virtual const char *getClassName() const override;

public slots:

    void valueChanged(int index);

protected:
    QComboBox *combo = nullptr;
    QLabel *label = nullptr;
};
#endif
