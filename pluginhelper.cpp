
#include "pluginhelper.h"
#include <QtWidgets/qmainwindow.h>
#include "qtablewidget.h"
#include "qtableview.h"
#include "qtabwidget.h"
#include "qtoolbar.h"
#include "qtoolbutton.h"
#include "utils.h"



//ChatWidget::ChatWidget(const QString& path, TsWebObject* webObject, QWidget *parent)
//create new widget and insert it into infoframe

PluginHelper::PluginHelper(const QString& pluginPath, QObject* parent)
	:QObject(parent)
{
	QTimer::singleShot(100, this, [=]() { initUi(); });

}

PluginHelper::~PluginHelper()
{
}

//finds mainwindow and initiates the menuitem
void PluginHelper::initUi()
{

	//parentwindow = utils::findMainWindow();

	//QWidget* ts3toolbar = utils::findWidget("ToolbarStretcher", parentwindow);


	//

	//toolmenu->addAction(toolsettings);
	//toolbutton->setMenu(toolmenu);

	//QToolBar* parenttoolbar = parentwindow->addToolBar(tr("toolbar"));
	//parenttoolbar->addAction(toolsettings);

	////insertmenu();



	printf("PLUGINHELPER RAN");


}

void PluginHelper::insertMenu()
{

	QMenu* chatMenus = new QMenu("AnnoyMenu");
	QAction* settingss = new QAction("&Settings", chatMenus);
	chatMenus->addAction(settingss);


	QMenuBar* menubars = parentwindow->menuBar();

	menubars->insertMenu(menubars->actions().last(), chatMenus);


}
