#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <map>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Rule;
enum class Probability;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void restart();
    void next();

private:
    void setAnswer();
    void setRule(std::unique_ptr<Rule>&& rule);

    Ui::Widget *ui;
    std::unique_ptr<Rule> m_rule;
    std::map<std::string, Probability> m_answers;
};
#endif // WIDGET_H
