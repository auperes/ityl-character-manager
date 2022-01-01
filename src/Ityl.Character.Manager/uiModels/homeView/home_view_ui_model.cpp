#include "home_view_ui_model.h"

namespace Ityl::Ui::UiModels
{
    HomeViewUIModel::HomeViewUIModel(QObject *parent)
        : QObject(parent)
        , _selectedCategory(nullptr)
    {

    }

    HomeViewUIModel::HomeViewUIModel(const DataModel::HomeView& homeView, QObject *parent)
        : QObject(parent)
    {
        resetHomeView(homeView);
    }

    void HomeViewUIModel::updateSelectedCategory(const QString &categoryName)
    {
        auto it = _categoriesByName.find(categoryName);

        if (it == _categoriesByName.end() || *it == _selectedCategory)
            return;

        _selectedCategory = *it;
        emit selectedCategoryChanged();
    }

    void HomeViewUIModel::selectElement(const QString& elementType, const QString& elementName)
    {
        if (elementType == "ethnie" || elementType == "group")
            emit elementSelected(elementType, elementName);
        if (elementType == "guild")
            emit elementSelected("group", QString("Guilde - " + elementName));
    }

    void HomeViewUIModel::resetHomeView(const DataModel::HomeView& homeView)
    {
        _categoryNames.clear();
        _categoriesByName.clear();

        for (const auto& category : homeView.categories())
        {
            _categoryNames.push_back(category.getName());
            _categoriesByName.insert(category.getName(), std::make_shared<HomeCategoryUiModel>(category.getElements()));
        }

        _selectedCategory = _categoriesByName.first();

        emit categoryNamesChanged();
        emit selectedCategoryChanged();
    }
}
