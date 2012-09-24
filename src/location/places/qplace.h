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

#ifndef QPLACE_H
#define QPLACE_H

#include <QtCore/QSharedDataPointer>
#include <QtLocation/qtlocation.h>

#include "qgeoaddress.h"
#include "qgeorectangle.h"
#include "qgeocoordinate.h"
#include "qgeolocation.h"
#include "qplacecategory.h"
#include "qplacecontent.h"
#include "qplaceratings.h"
#include "qplacereview.h"
#include "qplaceattribute.h"
#include "qplacecontactdetail.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE



class QString;
class QPlaceIcon;
class QPlacePrivate;

class Q_LOCATION_EXPORT QPlace
{
public:
    QPlace();
    QPlace(const QPlace &other);
    ~QPlace();

    QPlace &operator=(const QPlace &other);

    bool operator==(const QPlace &other) const;
    bool operator!=(const QPlace &other) const;

    QList<QPlaceCategory> categories() const;
    void setCategory(const QPlaceCategory &category);
    void setCategories(const QList<QPlaceCategory> &categories);
    QGeoLocation location() const;
    void setLocation(const QGeoLocation &location);
    QPlaceRatings ratings() const;
    void setRatings(const QPlaceRatings &ratings);
    QPlaceSupplier supplier() const;
    void setSupplier(const QPlaceSupplier &supplier);

    QString attribution() const;
    void setAttribution(const QString &attribution);

    QPlaceIcon icon() const;
    void setIcon(const QPlaceIcon &icon);

    QPlaceContent::Collection content(QPlaceContent::Type type) const;
    void setContent(QPlaceContent::Type type, const QPlaceContent::Collection &content);
    void insertContent(QPlaceContent::Type type, const QPlaceContent::Collection &content);

    int totalContentCount(QPlaceContent::Type type) const;
    void setTotalContentCount(QPlaceContent::Type type, int total);

    QString name() const;
    void setName(const QString &name);
    QString placeId() const;
    void setPlaceId(const QString &identifier);

    QString primaryPhone() const;
    QString primaryFax() const;
    QString primaryEmail() const;
    QUrl primaryWebsite() const;

    bool detailsFetched() const;
    void setDetailsFetched(bool fetched);

    QStringList extendedAttributeTypes() const;
    QPlaceAttribute extendedAttribute(const QString &attributeType) const;
    void setExtendedAttribute(const QString &attributeType, const QPlaceAttribute &attribute);
    void removeExtendedAttribute(const QString &attributeType);

    QStringList contactTypes() const;
    QList<QPlaceContactDetail> contactDetails(const QString &contactType) const;
    void setContactDetails(const QString &contactType, QList<QPlaceContactDetail> details);
    void appendContactDetail(const QString &contactType, const QPlaceContactDetail &detail);
    void removeContactDetails(const QString &contactType);

    QtLocation::Visibility visibility() const;
    void setVisibility(QtLocation::Visibility visibility);

    bool isEmpty() const;

private:
    QSharedDataPointer<QPlacePrivate> d_ptr;

    inline QPlacePrivate *d_func();
    inline const QPlacePrivate *d_func() const;
};

Q_DECLARE_TYPEINFO(QPlace, Q_MOVABLE_TYPE);

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QPlace)

QT_END_HEADER

#endif
