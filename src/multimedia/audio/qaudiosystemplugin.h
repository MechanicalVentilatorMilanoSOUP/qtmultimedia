/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef QAUDIOSYSTEMPLUGIN_H
#define QAUDIOSYSTEMPLUGIN_H

#include <QtCore/qstring.h>
#include <QtCore/qplugin.h>

#include <qtmultimediadefs.h>
#include <qtmedianamespace.h>

#include "qaudioformat.h"
#include "qaudiodeviceinfo.h"
#include "qaudiosystem.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Multimedia)

// Required for QDoc workaround
class QString;

struct Q_MULTIMEDIA_EXPORT QAudioSystemFactoryInterface
{
    virtual QList<QByteArray> availableDevices(QAudio::Mode) const = 0;
    virtual QAbstractAudioInput* createInput(const QByteArray& device) = 0;
    virtual QAbstractAudioOutput* createOutput(const QByteArray& device) = 0;
    virtual QAbstractAudioDeviceInfo* createDeviceInfo(const QByteArray& device, QAudio::Mode mode) = 0;
};

#define QAudioSystemFactoryInterface_iid \
    "org.qt-project.qt.audiosystemfactory/5.0"
Q_DECLARE_INTERFACE(QAudioSystemFactoryInterface, QAudioSystemFactoryInterface_iid)

// Required for QDoc workaround
class QString;

class Q_MULTIMEDIA_EXPORT QAudioSystemPlugin : public QObject, public QAudioSystemFactoryInterface
{
    Q_OBJECT
    Q_INTERFACES(QAudioSystemFactoryInterface)

public:
    QAudioSystemPlugin(QObject *parent = 0);
    ~QAudioSystemPlugin();

    virtual QList<QByteArray> availableDevices(QAudio::Mode) const = 0;
    virtual QAbstractAudioInput* createInput(const QByteArray& device) = 0;
    virtual QAbstractAudioOutput* createOutput(const QByteArray& device) = 0;
    virtual QAbstractAudioDeviceInfo* createDeviceInfo(const QByteArray& device, QAudio::Mode mode) = 0;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QAUDIOSYSTEMPLUGIN_H
