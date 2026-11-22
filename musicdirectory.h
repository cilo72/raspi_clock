#pragma once

#include <QStringList>

// Use the root of a mounted USB drive, or ~/Music when none is available.
QString musicDirectory();

QString musicDirectoryFromUsbMounts(QStringList mountPaths);
