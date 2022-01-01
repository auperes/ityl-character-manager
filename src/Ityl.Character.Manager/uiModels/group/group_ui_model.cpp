#include "group_ui_model.h"

#include <QQmlEngine>
#include <QStandardItemModel>

namespace Ityl::Ui::UiModels
{
    GroupUiModel::GroupUiModel()
        : QObject()
    {
    }

    GroupUiModel::GroupUiModel(const std::shared_ptr<DataModel::Group>& group, const QString& nationColor, QObject* parent)
        : QObject(parent)
        , _group(group)
        , _nationColor(nationColor)
        , _parts(new QStandardItemModel(this))
    {
        _parts->insertColumn(0);

        for (const auto& part : _group->getParts())
            addPart(*part);
    }

    void GroupUiModel::addPart(const DataModel::GroupPart& part)
    {
        const int newRow = _parts->rowCount();
        std::shared_ptr<GroupPartUiModel> groupPartUi = std::make_shared<GroupPartUiModel>(part);
        QQmlEngine::setObjectOwnership(groupPartUi.get(), QQmlEngine::CppOwnership);
        _parts->insertRow(newRow);
        _parts->setData(_parts->index(newRow, 0), QVariant::fromValue(groupPartUi.get()), Qt::DisplayRole);
        _partUiModels.push_back(groupPartUi);
        if (!groupPartUi->subgroupName().isEmpty())
            _partUiModelsBySubgroupName.insert(part.getSubgroupName(), groupPartUi);
    }
}
