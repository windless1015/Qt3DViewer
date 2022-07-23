#include "Qt3DViewer.h"
#include "openmeshApps/MeshViewerWidget.h"
#include <qstyle.h>
#include <qfiledialog.h>
#include <qstandardpaths.h>
#include <qdebug.h>

Qt3DViewer::Qt3DViewer(QWidget *parent)
    : QMainWindow(parent)
    , _meshViewerWidget(new MeshViewerWidget())
    , _importMeshAction(new QAction(this))
	,_setTexture(new QAction(this))
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

    createActions();
    createMenus();
    createToolbars();
}


void Qt3DViewer::displayMesh()
{
    OpenMesh::IO::Options opt;
    _meshViewerWidget->open_mesh("E:/skull.stl", opt);
}

void Qt3DViewer::createMenus()
{
    QMenu *fileMenu = this->menuBar()->addMenu(tr("File"));
    fileMenu->addAction(_importMeshAction);
	fileMenu->addAction(_setTexture);
}

void Qt3DViewer::createToolbars()
{
    ui.mainToolBar->addAction(_importMeshAction);
}

void Qt3DViewer::createActions()
{
    _importMeshAction->setIcon(QIcon(":/Qt3DViewer/Resources/images/importMesh.png"));
    _importMeshAction->setText(tr("Import Mesh"));
    connect(_importMeshAction, &QAction::triggered, this, &Qt3DViewer::importMesh);

	_setTexture->setText(tr("Set Texture"));
	connect(_setTexture, &QAction::triggered, this, &Qt3DViewer::setTexture);
}

void Qt3DViewer::importMesh()
{
	_meshViewerWidget->query_open_mesh_file();

    /*QString fileName = QFileDialog::getOpenFileName(this, tr("Import Mesh"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "STL(*.stl)");
    if (!fileName.isEmpty())
    {
        OpenMesh::IO::Options opt;
        _meshViewerWidget->open_mesh(fileName.toLocal8Bit().data(), opt);
    }*/
}

void Qt3DViewer::setTexture()
{
	_meshViewerWidget->query_open_texture_file();

}