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

#include "qplacesearchreply.h"
#include "qplacereply_p.h"


QT_BEGIN_NAMESPACE
class QPlaceSearchReplyPrivate : public QPlaceReplyPrivate
{
public:
    QPlaceSearchReplyPrivate(){}
    QList<QPlaceSearchResult> results;
    QPlaceSearchRequest searchRequest;
};

QT_END_NAMESPACE

QT_USE_NAMESPACE

/*!
    \class QPlaceSearchReply
    \inmodule QtLocation
    \ingroup QtLocation-places
    \ingroup QtLocation-places-replies
    \since Qt Location 5.0

    \brief The QPlaceSearchReply class manages a place search operation started by an
    instance of QPlaceManager.

    See \l {Discovery/Search} for an example on how to use a search reply.
    \sa QPlaceSearchRequest, QPlaceManager
*/

/*!
    Constructs a search reply with a given \a parent.
*/
QPlaceSearchReply::QPlaceSearchReply(QObject *parent)
    : QPlaceReply(new QPlaceSearchReplyPrivate, parent)
{
}

/*!
    Destroys the search reply.
*/
QPlaceSearchReply::~QPlaceSearchReply()
{
}

/*!
    Returns the type of reply.
*/
QPlaceReply::Type QPlaceSearchReply::type() const
{
    return QPlaceReply::SearchReply;
}

 /*!
    Returns a list of search results;
*/
QList<QPlaceSearchResult> QPlaceSearchReply::results() const
{
    Q_D(const QPlaceSearchReply);
    return d->results;
}

/*!
    Sets the list of search \a results.
*/
void QPlaceSearchReply::setResults(const QList<QPlaceSearchResult> &results)
{
    Q_D(QPlaceSearchReply);
    d->results = results;
}

/*!
    Returns the search request that was used to generate this reply.
*/
QPlaceSearchRequest QPlaceSearchReply::request() const
{
    Q_D(const QPlaceSearchReply);
    return d->searchRequest;
}

/*!
    Sets the search \a request used to generate this reply.
*/
void QPlaceSearchReply::setRequest(const QPlaceSearchRequest &request)
{
    Q_D(QPlaceSearchReply);
    d->searchRequest = request;
}
