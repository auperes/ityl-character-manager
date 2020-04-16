#include "home_view_ui_model.h"

namespace Ityl::UiModel
{
    HomeViewUIModel::HomeViewUIModel(QObject *parent)
        : QObject(parent)
        , _selectedCategory(nullptr)
    {

    }

    HomeViewUIModel::HomeViewUIModel(const DataModel::HomeView& homeView, QObject *parent)
        : QObject(parent)
    {
        for (const auto& category : homeView.categories())
        {
            _categoryNames.push_back(category.getName());
            _categoriesByName.insert(category.getName(), std::make_shared<HomeCategoryUiModel>(category.getElements()));
        }

        _selectedCategory = _categoriesByName.first();
    }

    void HomeViewUIModel::updateSelectedCategory(const QString &categoryName)
    {
        auto it = _categoriesByName.find(categoryName);

        if (it == _categoriesByName.end() || *it == _selectedCategory)
            return;

        _selectedCategory = *it;
        emit selectedCategoryChanged();
    }
}
