#pragma once

#include <QObject>

#include <converters/data_model_converters.h>
#include <group/group_info.h>

namespace Ityl::Ui::UiModels
{
    class GroupInfoUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString name READ name CONSTANT)
        Q_PROPERTY(QString subGroupName READ subGroupName CONSTANT)
        Q_PROPERTY(QString type READ type CONSTANT)
        Q_PROPERTY(bool isOld READ isOld CONSTANT)
        Q_PROPERTY(QString styledGroupInfo READ styledGroupInfo CONSTANT)

    public:
        explicit GroupInfoUiModel(QObject *parent = nullptr);
        explicit GroupInfoUiModel(const DataModel::GroupInfo& groupInfo, QObject *parent = nullptr);

        ~GroupInfoUiModel() override = default;

        QString name() const { return _groupInfo.getName(); }
        QString subGroupName() const { return _groupInfo.getSubgroupName(); }
        QString type() const { return DataModel::Converters::convertGroupType(_groupInfo.getType()); }
        bool isOld() const { return _groupInfo.getIsOld(); }
        QString styledGroupInfo() const;

    signals:

    private:
        DataModel::GroupInfo _groupInfo;

        QString getColor() const;
        QString getRichTextSubGroup() const;
        QString getRichTextType() const;
        QString getRichTextGroup() const;
    };
}
