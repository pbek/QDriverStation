/*
 * Copyright (c) 2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of the LibDS, which is released under the MIT license.
 * For more information, please read the LICENSE file in the root directory
 * of this project.
 */

#include <QPair>
#include <QObject>
#include <QHostInfo>

/**
 * @brief Performs host lookups to obtain socket-usable IP addresses
 */
class Lookup : public QObject {
    Q_OBJECT

  signals:
    void lookupFinished (const QString& original, const QHostAddress& address);

  public:
    explicit Lookup();

  public slots:
    void lookup (const QString& name);

  private slots:
    void clearCache();
    void onLookupFinished (const QHostInfo& info);

  private:
    bool isOnCache (const QString& name);
    QHostAddress getAddress (const QString& name);

  private:
    QList<QPair<QString, QHostAddress>> m_hosts;
};
