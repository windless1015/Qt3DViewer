#include "Qt3DViewer.h"
#include <QtWidgets/QApplication>

#include <iostream>
#include <fstream>
#include <QApplication>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenuBar>
#include <QFileDialog>

#include "openmeshApps/MeshViewerWidget.h"

void create_menu(QMainWindow& w);

int main(int argc, char *argv[])
{

	//MyMesh mesh;
	//// generate vertices
	//MyMesh::VertexHandle vhandle[8];
	//vhandle[0] = mesh.add_vertex(MyMesh::Point(-1, -1, 1));
	//vhandle[1] = mesh.add_vertex(MyMesh::Point(1, -1, 1));
	//vhandle[2] = mesh.add_vertex(MyMesh::Point(1, 1, 1));
	//vhandle[3] = mesh.add_vertex(MyMesh::Point(-1, 1, 1));
	//vhandle[4] = mesh.add_vertex(MyMesh::Point(-1, -1, -1));
	//vhandle[5] = mesh.add_vertex(MyMesh::Point(1, -1, -1));
	//vhandle[6] = mesh.add_vertex(MyMesh::Point(1, 1, -1));
	//vhandle[7] = mesh.add_vertex(MyMesh::Point(-1, 1, -1));
	//// generate (quadrilateral) faces
	//std::vector<MyMesh::VertexHandle>  face_vhandles;
	//face_vhandles.clear();
	//face_vhandles.push_back(vhandle[0]);
	//face_vhandles.push_back(vhandle[1]);
	//face_vhandles.push_back(vhandle[2]);
	//face_vhandles.push_back(vhandle[3]);
	//mesh.add_face(face_vhandles);

	//face_vhandles.clear();
	//face_vhandles.push_back(vhandle[7]);
	//face_vhandles.push_back(vhandle[6]);
	//face_vhandles.push_back(vhandle[5]);
	//face_vhandles.push_back(vhandle[4]);
	//mesh.add_face(face_vhandles);
	//face_vhandles.clear();
	//face_vhandles.push_back(vhandle[1]);
	//face_vhandles.push_back(vhandle[0]);
	//face_vhandles.push_back(vhandle[4]);
	//face_vhandles.push_back(vhandle[5]);
	//mesh.add_face(face_vhandles);
	//face_vhandles.clear();
	//face_vhandles.push_back(vhandle[2]);
	//face_vhandles.push_back(vhandle[1]);
	//face_vhandles.push_back(vhandle[5]);
	//face_vhandles.push_back(vhandle[6]);
	//mesh.add_face(face_vhandles);
	//face_vhandles.clear();
	//face_vhandles.push_back(vhandle[3]);
	//face_vhandles.push_back(vhandle[2]);
	//face_vhandles.push_back(vhandle[6]);
	//face_vhandles.push_back(vhandle[7]);
	//mesh.add_face(face_vhandles);
	//face_vhandles.clear();
	//face_vhandles.push_back(vhandle[0]);
	//face_vhandles.push_back(vhandle[3]);
	//face_vhandles.push_back(vhandle[7]);
	//face_vhandles.push_back(vhandle[4]);
	//mesh.add_face(face_vhandles);
	//// write mesh to output.obj

	//if (!OpenMesh::IO::write_mesh(mesh, "D:/output.obj"))
	//{
	//	std::cerr << "Cannot write mesh to file 'output.off'" << std::endl;
	//}

	QApplication a(argc, argv);
	Qt3DViewer w;
	w.show();
	return a.exec();





	//QApplication::setColorSpec(QApplication::CustomColor);
	//QApplication app(argc, argv);

	//int c;
	//OpenMesh::IO::Options opt;


	//// enable most options for now
	//opt += OpenMesh::IO::Options::VertexColor;
	//opt += OpenMesh::IO::Options::VertexNormal;
	//opt += OpenMesh::IO::Options::VertexTexCoord;
	//opt += OpenMesh::IO::Options::FaceColor;
	//opt += OpenMesh::IO::Options::FaceNormal;
	//opt += OpenMesh::IO::Options::FaceTexCoord;

	//// create widget
	//QMainWindow mainWin;
	//MeshViewerWidget w(&mainWin);
	//w.setOptions(opt);
	//mainWin.setCentralWidget(&w);

	//create_menu(mainWin);

	//// static mesh, hence use strips
	////w.enable_strips();

	//mainWin.resize(640, 480);
	//mainWin.show();

	//// load scene if specified on the command line
	//if (optind < argc)
	//{
	//	w.open_mesh_gui(argv[optind]);
	//}

	//if (++optind < argc)
	//{
	//	w.open_texture_gui(argv[optind]);
	//}

	//return app.exec();

}

void create_menu(QMainWindow& w)
{
	using namespace Qt;
	QMenu* fileMenu = w.menuBar()->addMenu(w.tr("&File"));

	QAction* openAct = new QAction(w.tr("&Open mesh..."), &w);
	openAct->setShortcut(w.tr("Ctrl+O"));
	openAct->setStatusTip(w.tr("Open a mesh file"));
	QObject::connect(openAct, SIGNAL(triggered()), w.centralWidget(), SLOT(query_open_mesh_file()));
	fileMenu->addAction(openAct);

	QAction* texAct = new QAction(w.tr("Open &texture..."), &w);
	texAct->setShortcut(w.tr("Ctrl+T"));
	texAct->setStatusTip(w.tr("Open a texture file"));
	QObject::connect(texAct, SIGNAL(triggered()), w.centralWidget(), SLOT(query_open_texture_file()));
	fileMenu->addAction(texAct);
}
