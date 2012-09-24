/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtLocation module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QGEOSATELLITEINFOSOURCE_NPE_BACKEND_H
#define QGEOSATELLITEINFOSOURCE_NPE_BACKEND_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qgeosatelliteinfosource.h"
#include <qtimer.h>
#include <locationdaemonconnection.h>


class QGeoSatelliteInfoSourceNpeBackend: public QGeoSatelliteInfoSource
{
    Q_OBJECT

public:
    QGeoSatelliteInfoSourceNpeBackend(QObject *parent = 0);
    bool init();
    void setUpdateInterval(int interval);
    int minimumUpdateInterval() const;
    QGeoSatelliteInfoSource::Error error() const;

public Q_SLOTS:
    void startUpdates();
    void stopUpdates();
    void requestUpdate(int timeout = 5000);

private:
    void setError(QGeoSatelliteInfoSource::Error satelliteError);
    void shutdownRequestSession();
    LocationDaemonConnection *m_locationdConn;
    bool satOngoing;
    QTimer *requestTimer;
    QGeoSatelliteInfoSource::Error mSatelliteError;


private Q_SLOTS:
    void onSatelliteUpdate(const QList<SatelliteData> &satellites);
    void onConnectionError(LocationDaemonConnection::SocketError socketError);
    void requestTimerExpired();
};

#endif // QGEOSATELLITEINFOSOURCE_NPE_BACKEND_H
