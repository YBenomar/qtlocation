/****************************************************************************
**
** Copyright (C) 2018 Mapbox, Inc.
**
** This file is part of the QtLocation module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qgeoroutemapbox.h"

#include <QtLocation/QGeoRoute>
#include <QtLocation/private/qgeoroute_p.h>
#include <QtLocation/private/qgeoroutemapbox_p.h>

QT_BEGIN_NAMESPACE

QGeoRouteMapbox::QGeoRouteMapbox(const QGeoRoute &route)
    : QGeoRoute(QExplicitlySharedDataPointer<QGeoRoutePrivateMapbox>(new QGeoRoutePrivateMapbox(*static_cast<const QGeoRoutePrivateMapbox *>(QGeoRoutePrivate::routePrivateData(route)))))
{
}

QGeoRouteMapbox::~QGeoRouteMapbox()
{
}

void QGeoRouteMapbox::setRouteQueryReply(const QByteArray &routeQueryReply)
{
    static_cast<QGeoRoutePrivateMapbox *>(d().data())->setRouteQueryReply(routeQueryReply);
}

QByteArray QGeoRouteMapbox::routeQueryReply() const
{
    return static_cast<const QGeoRoutePrivateMapbox *>(QGeoRoutePrivate::routePrivateData(*this))->routeQueryReply();
}

/* ------------------------------------------------------------------------ */

QGeoRoutePrivateMapbox::QGeoRoutePrivateMapbox()
    : QGeoRoutePrivateDefault()
{
}

QGeoRoutePrivateMapbox::QGeoRoutePrivateMapbox(const QGeoRoutePrivateMapbox &other)
    : QGeoRoutePrivateDefault(other)
{
}

QGeoRoutePrivateMapbox::~QGeoRoutePrivateMapbox() {}

QString QGeoRoutePrivateMapbox::engineName() const
{
    return QStringLiteral("mapbox");
}

void QGeoRoutePrivateMapbox::setRouteQueryReply(const QByteArray &routeQueryReply)
{
    m_routeQueryReply = routeQueryReply;
}

QByteArray QGeoRoutePrivateMapbox::routeQueryReply() const
{
    return m_routeQueryReply;
}

QT_END_NAMESPACE
