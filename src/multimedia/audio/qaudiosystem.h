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

#ifndef QAUDIOSYSTEM_H
#define QAUDIOSYSTEM_H

#include <qtmultimediadefs.h>
#include <qtmedianamespace.h>

#include "qaudio.h"
#include "qaudioformat.h"
#include "qaudiodeviceinfo.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Multimedia)

// Required for QDoc workaround
class QString;

class Q_MULTIMEDIA_EXPORT QAbstractAudioDeviceInfo : public QObject
{
    Q_OBJECT

public:
    virtual QAudioFormat preferredFormat() const = 0;
    virtual bool isFormatSupported(const QAudioFormat &format) const = 0;
    virtual QString deviceName() const = 0;
    virtual QStringList supportedCodecs() = 0;
    virtual QList<int> supportedSampleRates() = 0;
    virtual QList<int> supportedChannelCounts() = 0;
    virtual QList<int> supportedSampleSizes() = 0;
    virtual QList<QAudioFormat::Endian> supportedByteOrders() = 0;
    virtual QList<QAudioFormat::SampleType> supportedSampleTypes() = 0;
};

class Q_MULTIMEDIA_EXPORT QAbstractAudioOutput : public QObject
{
    Q_OBJECT

public:
    virtual void start(QIODevice *device) = 0;
    virtual QIODevice* start() = 0;
    virtual void stop() = 0;
    virtual void reset() = 0;
    virtual void suspend() = 0;
    virtual void resume() = 0;
    virtual int bytesFree() const = 0;
    virtual int periodSize() const = 0;
    virtual void setBufferSize(int value) = 0;
    virtual int bufferSize() const = 0;
    virtual void setNotifyInterval(int milliSeconds) = 0;
    virtual int notifyInterval() const = 0;
    virtual qint64 processedUSecs() const = 0;
    virtual qint64 elapsedUSecs() const = 0;
    virtual QAudio::Error error() const = 0;
    virtual QAudio::State state() const = 0;
    virtual void setFormat(const QAudioFormat& fmt) = 0;
    virtual QAudioFormat format() const = 0;
    virtual void setVolume(qreal) {}
    virtual qreal volume() const { return 1.0; }
    virtual QString category() const { return QString(); }
    virtual void setCategory(const QString &) { }

Q_SIGNALS:
    void errorChanged(QAudio::Error);
    void stateChanged(QAudio::State);
    void notify();
};

class Q_MULTIMEDIA_EXPORT QAbstractAudioInput : public QObject
{
    Q_OBJECT

public:
    virtual void start(QIODevice *device) = 0;
    virtual QIODevice* start() = 0;
    virtual void stop() = 0;
    virtual void reset() = 0;
    virtual void suspend()  = 0;
    virtual void resume() = 0;
    virtual int bytesReady() const = 0;
    virtual int periodSize() const = 0;
    virtual void setBufferSize(int value) = 0;
    virtual int bufferSize() const = 0;
    virtual void setNotifyInterval(int milliSeconds) = 0;
    virtual int notifyInterval() const = 0;
    virtual qint64 processedUSecs() const = 0;
    virtual qint64 elapsedUSecs() const = 0;
    virtual QAudio::Error error() const = 0;
    virtual QAudio::State state() const = 0;
    virtual void setFormat(const QAudioFormat& fmt) = 0;
    virtual QAudioFormat format() const = 0;
    virtual void setVolume(qreal) {}
    virtual qreal volume() const { return 1.0; }

Q_SIGNALS:
    void errorChanged(QAudio::Error);
    void stateChanged(QAudio::State);
    void notify();
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QAUDIOSYSTEM_H
