#include "Qt3DViewer.h"
#include <qboxlayout.h>
#include "openmeshApps/MeshViewerWidget.h"

Qt3DViewer::Qt3DViewer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    _meshViewerWidget = new MeshViewerWidget(this);
    _meshViewerWidget->resize(640, 480);
    _meshViewerWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);//ÆÌÂú²¼¾Ö
    displayMesh();
    QVBoxLayout* vbox = new QVBoxLayout();

    OpenMesh::IO::Options opt;

    // enable most options for now
    opt += OpenMesh::IO::Options::VertexColor;
    opt += OpenMesh::IO::Options::VertexNormal;
    opt += OpenMesh::IO::Options::VertexTexCoord;
    opt += OpenMesh::IO::Options::FaceColor;
    opt += OpenMesh::IO::Options::FaceNormal;
    opt += OpenMesh::IO::Options::FaceTexCoord;

    _meshViewerWidget->setOptions(opt);
    vbox->addWidget(_meshViewerWidget);

    vbox->setContentsMargins(0, 0, 0, 0);

    setLayout(vbox);
}


void Qt3DViewer::displayMesh()
{
    OpenMesh::IO::Options opt;
    _meshViewerWidget->open_mesh("E:/skull.stl", opt);
}