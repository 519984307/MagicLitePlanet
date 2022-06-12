#include "posterwork.h"
#include <QDebug>

PosterWork::PosterWork(QObject *parent)
	: QObject(parent)
{
    db_service.addDatabase(DB, "PosterManageWork_DB");
}

PosterWork::~PosterWork()
{
}

void PosterWork::working()
{
    DB.open();
    if (workType == -1)
        return;
    if (workType != 1)
    {
        tabModel->setTable("magic_contents");
        tabModel->setSort(tabModel->fieldIndex("c_id"), Qt::DescendingOrder);
        tabModel->setHeaderData(tabModel->fieldIndex("c_id"), Qt::Horizontal, "���");
        tabModel->setHeaderData(tabModel->fieldIndex("title"), Qt::Horizontal, "����");
        tabModel->setHeaderData(tabModel->fieldIndex("author_id"), Qt::Horizontal, "������");
        tabModel->select();
        
        emit contentsWorkFinished();
    }
    else
    {
        manageModel->setTable("magic_contents");
        manageModel->setSort(manageModel->fieldIndex("c_id"), Qt::DescendingOrder);
        manageModel->setEditStrategy(QSqlTableModel::OnRowChange);
        manageModel->setHeaderData(manageModel->fieldIndex("c_id"), Qt::Horizontal, "���");
        manageModel->setHeaderData(manageModel->fieldIndex("title"), Qt::Horizontal, "����");
        manageModel->setHeaderData(manageModel->fieldIndex("author_id"), Qt::Horizontal, "������");
        manageModel->select();
        qDebug() << "posterWork���";
        emit contentsManageWorkFinished();
    }
}

QSqlDatabase PosterWork::getDB()
{
    return DB;
}

void PosterWork::submitAll()
{
    manageModel->submitAll();
}

void PosterWork::setModel(QSqlTableModel* model)
{
    tabModel = model;
}

void PosterWork::setManageModel(QSqlTableModel* model)
{
    manageModel = model;
}

void PosterWork::setWorkType(int type)
{
    workType = type;
}
