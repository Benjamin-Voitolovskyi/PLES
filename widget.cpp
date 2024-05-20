#include "widget.h"
#include "ui_widget.h"
#include "initialrule.h"
#include "Probability.h"
#include "constants.h"

#include <QMessageBox>
#include <QLabel>
#include <QPixmap>
#include <QRadioButton>
#include <QVBoxLayout>

#include <sstream>
#include <stdexcept>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("PLES");
    setWindowIcon(QIcon(":/images/images/code.png"));
    restart();
    connect(ui->restartButton, &QPushButton::clicked, [this](){ restart(); });
    connect(ui->nextButton, &QPushButton::clicked, [this](){ next(); });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::restart()
{
    m_answers.clear();
    for (const auto& progLang : Constants::PROGRAMMING_LANGUAGES)
        m_answers.emplace(progLang, Probability::UNLIKELY);
    setRule(std::make_unique<InitialRule>());
}

void Widget::next()
{
    const auto radioButtons = ui->answersBox->findChildren<QRadioButton*>();
    std::string selectedDomain;

    for (const auto radioButton : radioButtons)
    {
        if (radioButton->isChecked())
        {
            selectedDomain = radioButton->text().toStdString();
            break;
        }
    }

    try
    {
        setRule(m_rule->getChildRule(selectedDomain));
    }
    catch (const std::invalid_argument& ex)
    {
        QMessageBox messageBox;
        messageBox.setText(QString(ex.what()));
        messageBox.exec();
    }
}

void Widget::setAnswer()
{
    std::vector<std::string> certainAnswers;
    std::vector<std::string> possibleAnswers;

    for (const auto& [progLang, probability] : m_answers)
    {
        switch (probability)
        {
        case Probability::CERTAIN:
            certainAnswers.push_back(progLang);
            break;
        case Probability::POSSIBLE:
            possibleAnswers.push_back(progLang);
            break;
        default:
            break;
        }
    }

    while (ui->imagesLayout->count() > 0)
    {
        auto item = ui->imagesLayout->takeAt(0);
        auto widget = item->widget();
        if (widget)
            delete widget;
        delete item;
    }

    std::stringstream answer;
    if (!certainAnswers.empty())
    {
        ui->imagesLayout->addStretch();
        answer << "The best choice" << (certainAnswers.size() == 1 ? " is " : "s are ");
        for (size_t idx = 0; idx < certainAnswers.size(); ++idx)
        {
            answer << certainAnswers[idx];
            answer << (idx == certainAnswers.size() - 1 ? "." : ", ");

            QLabel* imageLabel = new QLabel;
            QPixmap image(QString::fromStdString(Constants::PROG_LANG_TO_IMAGE.at(certainAnswers[idx])));
            image = image.scaled(Constants::IMAGE_SIZE, Constants::IMAGE_SIZE);
            imageLabel->setPixmap(image);
            ui->imagesLayout->addWidget(imageLabel);
        }
        ui->imagesLayout->addStretch();
        answer << std::endl;
    }

    if (!possibleAnswers.empty())
    {
        answer << "Possible choice" << (possibleAnswers.size() == 1 ? " is " : "s are ");
        for (size_t idx = 0; idx < possibleAnswers.size(); ++idx)
        {
            answer << possibleAnswers[idx];
            answer << (idx == possibleAnswers.size() - 1 ? "." : ", ");
        }
        answer << std::endl;
    }

    ui->answer->setText(QString::fromStdString(answer.str()));
}

void Widget::setRule(std::unique_ptr<Rule>&& rule)
{
    m_rule = std::move(rule);
    ui->Question->setText(QString::fromStdString(m_rule->getPrompt()));
    m_rule->run(m_answers);
    if (!m_rule->hasNextRules())
    {
        ui->nextButton->hide();
        ui->answersBox->hide();
        ui->Question->hide();
    }
    else
    {
        ui->nextButton->show();
        ui->answersBox->show();
        ui->Question->show();
    }
    setAnswer();

    if (ui->answersBox->layout())
        QWidget().setLayout(ui->answersBox->layout());

    QVBoxLayout* layout = new QVBoxLayout();
    for (const auto& domain : m_rule->getNextRules())
    {
        QRadioButton* radioButton = new QRadioButton(QString::fromStdString(domain));
        layout->addWidget(radioButton);
    }
    ui->answersBox->setLayout(layout);
}
