#pragma once

#include <QObject>

namespace Ityl::UI
{
    class GroupInfoUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString name READ name CONSTANT)
        Q_PROPERTY(QString role READ role CONSTANT)
        Q_PROPERTY(QString subGroupName READ subGroupName CONSTANT)
        Q_PROPERTY(QString type READ type CONSTANT)
        Q_PROPERTY(bool isOld READ isOld CONSTANT)
        Q_PROPERTY(QString styledGroupInfo READ styledGroupInfo CONSTANT)

    public:
        explicit GroupInfoUiModel(QObject *parent = nullptr);

        ~GroupInfoUiModel() override = default;

        QString name() const { return _name; }
        QString role() const { return _role; }
        QString subGroupName() const { return _subGroupName; }
        QString type() const { return _type; }
        bool isOld() const { return _isOld; }
        QString styledGroupInfo() const;

    signals:

    private:
        QString _name;
        QString _role;
        QString _subGroupName;
        QString _type;
        bool _isOld;

        QString getColor() const;
        QString getRichTextRole() const;
        QString getRichTextType() const;
        QString getRichTextGroup() const;
    };
}
