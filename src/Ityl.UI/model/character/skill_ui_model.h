#pragma once

#include <QObject>

namespace Ityl::UI
{
    class SkillUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString skillName READ skillName CONSTANT)
        Q_PROPERTY(QString skillValues READ skillValues CONSTANT)

    public:
        explicit SkillUiModel(QObject *parent = nullptr);

        ~SkillUiModel() override = default;

        QString skillName() const { return _skillName; }
        QString skillValues() const {return _skillValues; }

    signals:

    public slots:

    private:
        QString _skillName;
        QString _skillValues;
    };
}
