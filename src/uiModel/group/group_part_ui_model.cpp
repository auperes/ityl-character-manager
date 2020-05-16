#include "group_part_ui_model.h"

#include <QQmlEngine>
#include <QStandardItemModel>

namespace Ityl::UiModel
{
    GroupPartUiModel::GroupPartUiModel(const DataModel::GroupPart& part, QObject *parent)
        : QObject(parent)
        , _part(part)
        , _currentCharacters(std::make_shared<CharactersUiCollection>())
        , _oldCharacters(std::make_shared<CharactersUiCollection>())
        , _parts(new QStandardItemModel(this))
    {
        if (!_part.getParts().empty())
        {
            _parts->insertColumn(0);

            for (const auto& part : _part.getParts())
                addPart(part);
        }
    }

    void GroupPartUiModel::addPart(const DataModel::GroupPart& part)
    {
        const int newRow = _parts->rowCount();
        std::shared_ptr<GroupPartUiModel> groupPartUi = std::make_shared<GroupPartUiModel>(part);
        QQmlEngine::setObjectOwnership(groupPartUi.get(), QQmlEngine::CppOwnership);
        _parts->insertRow(newRow);
        _parts->setData(_parts->index(newRow, 0), QVariant::fromValue(groupPartUi.get()), Qt::DisplayRole);
        _partUiModels.push_back(std::move(groupPartUi));
    }
}
