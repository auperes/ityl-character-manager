#pragma once

#include <memory>

#include <QList>
#include <QMap>
#include <QObject>
#include <QString>

#include <homeView/home_view.h>

#include "home_category_ui_model.h"

namespace Ityl::Ui::UiModels
{
    class HomeViewUIModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QStringList categoryNames READ getCategoryNames NOTIFY categoryNamesChanged)
        Q_PROPERTY(HomeCategoryUiModel* selectedCategory READ getSelectedCategory NOTIFY selectedCategoryChanged)

    public:
        explicit HomeViewUIModel(QObject *parent = nullptr);
        explicit HomeViewUIModel(const DataModel::HomeView& homeView, QObject *parent = nullptr);

        ~HomeViewUIModel() override = default;

        const QStringList getCategoryNames() const { return _categoryNames; }
        HomeCategoryUiModel* getSelectedCategory() const { return _selectedCategory.get(); }

    signals:
        void selectedCategoryChanged();
        void categoryNamesChanged();
        void elementSelected(const QString& elementType, const QString& elementName);

    public slots:
        void updateSelectedCategory(const QString& categoryName);
        void selectElement(const QString& elementType, const QString& elementName);
        void resetHomeView(const DataModel::HomeView& homeView);

    private:
        QList<QString> _categoryNames;
        std::shared_ptr<HomeCategoryUiModel> _selectedCategory;
        QMap<QString, std::shared_ptr<HomeCategoryUiModel>> _categoriesByName;
    };
}
