#include "veicolotypebox.h"

VeicoloTypeBox::VeicoloTypeBox(QWidget* parent):
    QComboBox (parent)
{
addItem("Tipo Inserimento");
addItem("auto");
addItem("camion");
addItem("moto");
addItem("carrozzeria");
addItem("motore");
}
