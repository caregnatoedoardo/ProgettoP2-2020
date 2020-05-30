#ifndef VEICOLOTIPEBOX_H
#define VEICOLOTIPEBOX_H

#include <QComboBox>
#include <QObject>
#include <string>

using std::string;

class VeicoloTipeBox : public QComboBox
{
public:
    VeicoloTipeBox(QWidget* = nullptr);
};

#endif // VEICOLOTIPEBOX_H
