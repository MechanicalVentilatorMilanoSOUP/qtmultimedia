######################################################################
#
# Qt Multimedia
#
######################################################################

TEMPLATE = subdirs
QT_FOR_CONFIG += multimedia-private

SUBDIRS += m3u

qtHaveModule(quick) {
   SUBDIRS += videonode
}

android {
   SUBDIRS += android opensles
}

qnx {
    qtConfig(mmrenderer): SUBDIRS += qnx
    SUBDIRS += audiocapture
}

qnx {
    SUBDIRS += qnx-audio
}

win32 {
    qtConfig(wasapi): SUBDIRS += wasapi
}

win32:!winrt {
    SUBDIRS += audiocapture \
               windowsaudio

    qtConfig(directshow): SUBDIRS += directshow
    qtConfig(wmf): SUBDIRS += wmf
}


winrt {
    SUBDIRS += winrt \
               audiocapture
}

qtConfig(gstreamer): SUBDIRS += gstreamer

unix:!mac:!android {
    !qtConfig(gstreamer): SUBDIRS += audiocapture

    qtConfig(pulseaudio): SUBDIRS += pulseaudio
    qtConfig(alsa): SUBDIRS += alsa
}

darwin:!watchos {
    SUBDIRS += audiocapture coreaudio
    qtConfig(avfoundation): SUBDIRS += avfoundation
}

qtConfig(resourcepolicy) {
    SUBDIRS += resourcepolicy
}

