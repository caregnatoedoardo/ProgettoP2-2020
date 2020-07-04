#ifndef VEICOLOTIPEBOX_H
#define VEICOLOTIPEBOX_H

#include <QComboBox>
#include <QObject>
#include <string>

using std::string;

class VeicoloTypeBox : public QComboBox
{
public:
    VeicoloTypeBox(QWidget* = nullptr);
};
#endif // VEICOLOTIPEBOX_H
