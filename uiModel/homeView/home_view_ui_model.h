#pragma once

#include <QList>
#include <QMap>
#include <QObject>
#include <QString>

#include "../../dataModel/homeView/home_view.h"
#include "home_category_ui_model.h"

namespace Ityl::UiModel
{
    class HomeViewUIModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QStringList categoryNames READ getCategoryNames CONSTANT)
        Q_PROPERTY(HomeCategoryUiModel* selectedCategory READ getSelectedCategory NOTIFY selectedCategoryChanged)

    public:
        explicit HomeViewUIModel(QObject *parent = nullptr);
        explicit HomeViewUIModel(const DataModel::HomeView& homeView, QObject *parent = nullptr);

        const QStringList getCategoryNames() const { return _categoryNames; }
        HomeCategoryUiModel* getSelectedCategory() const { return _selectedCategory.get(); }

    signals:
        void selectedCategoryChanged();

    public slots:
        void updateSelectedCategory(const QString& categoryName);

    private:
        QList<QString> _categoryNames;
        std::shared_ptr<HomeCategoryUiModel> _selectedCategory;
        QMap<QString, std::shared_ptr<HomeCategoryUiModel>> _categoriesByName;
    };
}
