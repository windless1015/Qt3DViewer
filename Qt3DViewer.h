#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt3DViewer.h"

class MeshViewerWidget;

class Qt3DViewer : public QMainWindow
{
    Q_OBJECT

public:
    Qt3DViewer(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt3DViewerClass ui;

    MeshViewerWidget* _meshViewerWidget;

    void displayMesh();
};
