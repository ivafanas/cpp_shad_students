#include "SalesmanWidget.h"

#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>

// TODO: refactor SalesmanWidget in order to satisfy software requirement

SalesmanWidget::SalesmanWidget()
{
    auto* ver_layout = new QVBoxLayout;
    {
        QHBoxLayout* hor_layout = nullptr;

        // cities count setting
        hor_layout = new QHBoxLayout;
        {
            hor_layout->addWidget(new QLabel("cities count: "));
            hor_layout->addWidget(cities_count_edit = new QLineEdit);
            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);

        // thread count setting
        hor_layout = new QHBoxLayout;
        {
            hor_layout->addWidget(new QLabel("thread count: "));
            hor_layout->addWidget(thread_count_edit = new QLineEdit);
            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);

        // model control block
        hor_layout = new QHBoxLayout;
        {
            auto* start_button = new QPushButton("start");
            connect(start_button, &QPushButton::clicked, this, &SalesmanWidget::on_start);
            hor_layout->addWidget(start_button);

            auto* stop_button = new QPushButton("stop");
            connect(stop_button, &QPushButton::clicked, this, &SalesmanWidget::on_stop);
            hor_layout->addWidget(stop_button);

            auto* dump_button = new QPushButton("dump");
            connect(dump_button, &QPushButton::clicked, this, &SalesmanWidget::on_dump);
            hor_layout->addWidget(dump_button);

            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);

        // model status line
        hor_layout = new QHBoxLayout;
        {
            hor_layout->addWidget(new QLabel("model state: "));
            hor_layout->addWidget(model_status_label = new QLabel);
            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);
        
        // progress status line
        hor_layout = new QHBoxLayout;
        {
            hor_layout->addWidget(new QLabel("progress: "));
            hor_layout->addWidget(progress_status_label = new QLabel);
            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);

        ver_layout->addSpacing(10);

        // threads statistics
        for (int i = 0; i != 6; ++i)
        {
            const auto text = QString("thread %1:    %2\% completed, solution = %3")
                .arg(i)
                .arg((i + 1) * 10)
                .arg(42 + i);
            ver_layout->addWidget(new QLabel(text));
        }

        // for ui flexibility
        ver_layout->addStretch(2);
    }
    setLayout(ver_layout);

    // run |on_progress| every second
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SalesmanWidget::on_progress);
    timer->start(1000);

    setWindowTitle(tr("Salesman"));
    resize(400, 300);
}

void SalesmanWidget::on_start()
{
    // TODO: process start command
    model_status_label->setText(QString("started, cities = %1, threads = %2")
        .arg(cities_count_edit->text())
        .arg(thread_count_edit->text()));
}

void SalesmanWidget::on_stop()
{
    // TODO: process stop command
    model_status_label->setText("stopped");
}

void SalesmanWidget::on_progress()
{
    // TODO: process progress update
    static int calls_count = 0;
    ++calls_count;
    progress_status_label->setText(QString("call %1").arg(calls_count));
}

void SalesmanWidget::on_dump()
{
    // TODO: dump the latest result
    QMessageBox::warning(this, "dump", "dumping model to a model.txt");
}

