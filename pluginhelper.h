#pragma once

#include <QtWidgets>

class PluginHelper : public QObject
{
	Q_OBJECT

public:
	PluginHelper(const QString& pluginPath, QObject* parent = nullptr);
	~PluginHelper();

private slots:
	//void handleButton();

protected slots:
	//void test(QUrl q, QWebEnginePage::Feature f);


private:

	QMainWindow* parentwindow;
	QVBoxLayout* vLayout;
	QToolBar* toolbar;

	void initUi();
	void insertMenu();
	void handlelineedit();

};
