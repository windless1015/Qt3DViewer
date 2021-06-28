#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt3DViewer.h"

class MeshViewerWidget;
class QAction;
class QToolBar;
class Qt3DViewer : public QMainWindow
{
    Q_OBJECT

public:
    Qt3DViewer(QWidget *parent = Q_NULLPTR);
private slots:
    void importMesh();
private:
    Ui::Qt3DViewerClass ui;

    MeshViewerWidget* _meshViewerWidget;
    QAction* _importMeshAction;
    QToolBar* _fileToolBar;

    void displayMesh();
    void createMenus();
    void createToolbars();
    void createActions();
};
