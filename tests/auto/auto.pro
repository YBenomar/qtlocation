TEMPLATE = subdirs

#Place unit tests
SUBDIRS += qplace \
           qplaceattribute \
           qplacecategory \
           qplacecontactdetail \
           qplacecontentrequest \
           qplacedetailsreply \
           qplaceeditorial \
           qplacemanager \
           qplacemanager_unsupported \
           qplacemanager_nokia \
           qplacematchreply \
           qplacematchrequest \
           qplaceimage \
           qplaceratings \
           qplacereply \
           qplacereview \
           qplacesearchrequest \
           qplacesupplier \
           qplacesearchresult \
           qplacesearchreply \
           qplacesearchsuggestionreply \
           qplaceuser \
           qmlinterface \
           cmake

SUBDIRS += geotestplugin \
           placesplugin_unsupported \
           positionplugin \
           positionplugintest \
           qgeocodingmanagerplugins \
           qgeoaddress \
           qgeoareamonitor \
           qgeoshape \
           qgeorectangle \
           qgeocircle \
           qgeocameradata \
           qgeocameracapabilities \
           qgeocameratiles \
           qgeocodereply \
           qgeocodingmanager \
           qgeocoordinate \
           qgeolocation \
           qgeomaneuver \
           qgeomapscene \
           qgeopositioninfo \
           qgeopositioninfosource \
           qgeoroute \
           qgeoroutereply \
           qgeorouterequest \
           qgeoroutesegment \
           qgeoroutingmanager \
           qgeoroutingmanagerplugins \
           qgeosatelliteinfo \
           qgeosatelliteinfosource \
           qgeotilespec \
           qnmeapositioninfosource \
           declarative_core \
           qgeoroutexmlparser \
           qgeomapcontroller \
           maptype \
           nokia_services \
           doublevectors

!mac: SUBDIRS += declarative_ui

!isEmpty(QT.jsondb.name):SUBDIRS += qplacemanager_jsondb
