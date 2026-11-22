#include "musicdirectory.h"

#include <QDir>
#include <QFileInfo>
#include <QStorageInfo>

QString musicDirectory()
{
    QStringList usbDirectories;
    for (const QStorageInfo &storage : QStorageInfo::mountedVolumes())
    {
        if (!storage.isValid() || !storage.isReady())
            continue;

        // Resolve device aliases, then inspect the Linux device ancestry. This
        // distinguishes USB drives from the Raspberry Pi's SD card and disks.
        const QString device = QFileInfo(QString::fromLocal8Bit(storage.device())).canonicalFilePath();
        if (device.isEmpty())
            continue;
        const QString devicePath = QFileInfo(QStringLiteral("/sys/class/block/")
                                            + QFileInfo(device).fileName()).canonicalFilePath();
        if (devicePath.contains(QStringLiteral("/usb")))
            usbDirectories.append(storage.rootPath());
    }

    return musicDirectoryFromUsbMounts(usbDirectories);
}

QString musicDirectoryFromUsbMounts(QStringList mountPaths)
{
    // Pick consistently when several USB drives or partitions are mounted.
    mountPaths.sort();
    return mountPaths.isEmpty() ? QDir::home().filePath("Music")
                               : mountPaths.first();
}
