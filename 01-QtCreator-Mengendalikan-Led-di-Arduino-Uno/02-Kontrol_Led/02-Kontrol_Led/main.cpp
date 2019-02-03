#include "dialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setFixedSize(657, 207);   // ini supaya si form dialog nya ga bisa di ubah2 ukuran panjang x lebar nya
    w.setWindowTitle("Kontrol Led");
    w.show();

    return a.exec();
}
