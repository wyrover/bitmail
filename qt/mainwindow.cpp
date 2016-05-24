/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

//! [0]
#include <QtWidgets>

#include "mainwindow.h"
//! [0]

//! [1]
MainWindow::MainWindow()
//! [1] //! [2]
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    blist = new QListWidget;
    mainLayout->addWidget(blist);

    QVBoxLayout * rightLayout = new QVBoxLayout;

    mlist = new QListWidget;
    textEdit = new QPlainTextEdit;

    QHBoxLayout * btnLayout = new QHBoxLayout;
    btnSend = new QPushButton(tr("Send"));
    btnLayout->addWidget(btnSend);

    mainLayout->addLayout(rightLayout);

    QWidget * wrap = new QWidget(this);
    wrap->setLayout(mainLayout);
    setCentralWidget(wrap);

    createActions();
    createToolBars();
    createStatusBar();

    rightLayout->addWidget(mlist);
    rightLayout->addWidget(chatToolbar);
    rightLayout->addWidget(textEdit);
    rightLayout->addLayout(btnLayout);


    connect(textEdit->document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

#if defined(MACOSX)
    setUnifiedTitleAndToolBarOnMac(true);
#endif

    setWindowIcon(QIcon(":/images/bitmail.png"));
    setWindowTitle(tr("BitMail"));
}
//! [2]

//! [3]
void MainWindow::closeEvent(QCloseEvent *event)
//! [3] //! [4]
{
    if (true) {
        event->accept();
    }
}
//! [4]

//! [5]
void MainWindow::newFile()
//! [5] //! [6]
{

}
//! [6]

//! [7]
void MainWindow::open()
//! [7] //! [8]
{

}
//! [8]

//! [9]
bool MainWindow::save()
//! [9] //! [10]
{
    return true;
}
//! [10]

//! [15]
void MainWindow::documentWasModified()
//! [15] //! [16]
{

}
//! [16]

//! [17]
void MainWindow::createActions()
//! [17] //! [18]
{
    newAct = new QAction(QIcon(":/images/profile.png"), tr("&NewAccount"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new bitmail account profile"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    do {
        configAct = new QAction(QIcon(":/images/config.png"), tr("&Configure"), this);
        configAct->setStatusTip(tr("Configure current account"));
    }while(0);

//! [19]
    openAct = new QAction(QIcon(":/images/open.png"), tr("&Load..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Loading an existing account profile"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
//! [18] //! [19]

    saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    do {
        addAct = new QAction(QIcon(":/images/buddy.png"), tr("&NewBuddy"), this);
        addAct->setStatusTip(tr("Add a new buddy"));
    }while(0);

    do {
        strangerAct = new QAction(QIcon(":/images/stranger.png"), tr("&Stranger"), this);
        strangerAct->setStatusTip(tr("Notify me for messages from strangers"));
    }while(0);

    do{
        snapAct = new QAction(QIcon(":/images/snap.png"), tr("&Snapshot"), this);
        snapAct->setStatusTip(tr("snapshot"));
    }while(0);

    do{
        fileAct = new QAction(QIcon(":/images/file.png"), tr("&SendFile"), this);
        fileAct->setStatusTip(tr("SendFile"));
    }while(0);

    do{
        emojAct = new QAction(QIcon(":/images/emoj.png"), tr("&Emoj"), this);
        emojAct->setStatusTip(tr("SendEmoj"));
    }while(0);

    do{
        soundAct = new QAction(QIcon(":/images/sound.png"), tr("&Sound"), this);
        soundAct->setStatusTip(tr("Sound"));
    }while(0);

    do{
        videoAct = new QAction(QIcon(":/images/video.png"), tr("&Video"), this);
        videoAct->setStatusTip(tr("Video"));
    }while(0);

    do{
        styleAct = new QAction(QIcon(":/images/style.png"), tr("&Style"), this);
        styleAct->setStatusTip(tr("Style"));
    }while(0);

//! [23]
    addAct->setEnabled(true);
//! [23] //! [24]
    strangerAct->setEnabled(true);
}
//! [24]

//! [29] //! [30]
void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("Profile"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(configAct);
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("Buddies"));
    editToolBar->addAction(addAct);
    editToolBar->addAction(strangerAct);

    chatToolbar = addToolBar(tr("Chat"));
    chatToolbar->addAction(styleAct);
    chatToolbar->addAction(emojAct);
    chatToolbar->addAction(snapAct);
    chatToolbar->addAction(fileAct);
    chatToolbar->addAction(soundAct);
    chatToolbar->addAction(videoAct);
    chatToolbar->setIconSize(QSize(16,16));
}
//! [30]

//! [32]
void MainWindow::createStatusBar()
//! [32] //! [33]
{
    statusBar()->showMessage(tr("Ready"));
}
//! [33]

//! [42]
void MainWindow::loadProfile(const QString &fileName)
//! [42] //! [43]
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif

    textEdit->setPlainText(in.readAll());

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    //setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}
//! [43]

//! [44]
bool MainWindow::saveProfile(const QString &fileName)
//! [44] //! [45]
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif

    out << textEdit->toPlainText();

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    //setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}
//! [45]

//! [48]
QString MainWindow::strippedName(const QString &fullFileName)
//! [48] //! [49]
{
    return QFileInfo(fullFileName).fileName();
}
//! [49]
