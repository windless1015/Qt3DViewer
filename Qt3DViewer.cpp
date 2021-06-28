#include "Qt3DViewer.h"
#include "openmeshApps/MeshViewerWidget.h"

Qt3DViewer::Qt3DViewer(QWidget *parent)
    : QMainWindow(parent)
    , _meshViewerWidget(new MeshViewerWidget())
{
    ui.setupUi(this);

    OpenMesh::IO::Options opt;
    // enable most options for now
    opt += OpenMesh::IO::Options::VertexColor;
    opt += OpenMesh::IO::Options::VertexNormal;
    opt += OpenMesh::IO::Options::VertexTexCoord;
    opt += OpenMesh::IO::Options::FaceColor;
    opt += OpenMesh::IO::Options::FaceNormal;
    opt += OpenMesh::IO::Options::FaceTexCoord;

    _meshViewerWidget->setOptions(opt);
    setCentralWidget(_meshViewerWidget);
}


void Qt3DViewer::displayMesh()
{
    OpenMesh::IO::Options opt;
    _meshViewerWidget->open_mesh("E:/skull.stl", opt);
}