#include <QtCore/QCoreApplication>
#include <QImage>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc < 2) {
        qDebug() << "Specify input image as a parameter";
        return -1;
    }
    qDebug() << "Loading:" << argv[1];
    QImage image(argv[1]);
    qDebug() << "Image format:" << image.format();
    QImage alpha = image.alphaChannel();
    QImage rgb = image.convertToFormat(QImage::Format_RGB888);
    qDebug() << "Alpha image format:" << alpha.format();
    rgb.save("rgb.png");
    alpha.save("alpha.png");

    return 0;
}
