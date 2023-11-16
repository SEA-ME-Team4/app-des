#!/bin/sh
echo Setting QT_QPA_EGLFS_HIDECURSOR
export QT_QPA_EGLFS_HIDECURSOR=1
echo Setting HIDECURSOR enabled

# QT_QPA_PLATFORM=eglfs
# export QT_QPA_PLATFORM

LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH

########### FOR LOCAL ###########
export LD_LIBRARY_PATH=/home/mczb/local_workspace/DES03/capicxx-core-runtime/build
########### FOR LOCAL ###########

QT_PLUGIN_PATH=/usr/lib/x86_64-linux-gnu/qt5/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH

QT_IM_MODULE=qtvirtualkeyboard
export QT_IM_MODULE

exec /usr/lib/qt5/bin/appman -c head_unit/am-config.yaml --start-session-dbus --verbose -r "$@"