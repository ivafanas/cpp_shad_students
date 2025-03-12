#include "PalindromeWidget.h"

#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>

// TODO: refactor PalindromeWidget in order to satisfy software requirement

PalindromeWidget::PalindromeWidget()
{
    auto* ver_layout = new QVBoxLayout;
    {
        QHBoxLayout* hor_layout = nullptr;

        // cities count setting
        hor_layout = new QHBoxLayout;
        {
            str_len_edit_ = new QLineEdit();

            hor_layout->addWidget(new QLabel("string len: "));
            hor_layout->addWidget(str_len_edit_);
            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);

        // thread count setting
        hor_layout = new QHBoxLayout;
        {
            num_thr_edit_ = new QLineEdit();

            hor_layout->addWidget(new QLabel("thread count: "));
            hor_layout->addWidget(num_thr_edit_);
            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);

        // model control block
        hor_layout = new QHBoxLayout;
        {
            auto* start_button = new QPushButton("start");
            connect(start_button, &QPushButton::clicked, this, &PalindromeWidget::on_start);
            hor_layout->addWidget(start_button);

            auto* stop_button = new QPushButton("stop");
            connect(stop_button, &QPushButton::clicked, this, &PalindromeWidget::on_stop);
            hor_layout->addWidget(stop_button);

            auto* dump_button = new QPushButton("dump");
            connect(dump_button, &QPushButton::clicked, this, &PalindromeWidget::on_dump);
            hor_layout->addWidget(dump_button);

            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);

        // model status line
        hor_layout = new QHBoxLayout;
        {
            task_status_label_ = new QLabel();

            hor_layout->addWidget(new QLabel("model state: "));
            hor_layout->addWidget(task_status_label_);
            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);

        // progress status line
        hor_layout = new QHBoxLayout;
        {
            progress_status_label_ = new QLabel();

            hor_layout->addWidget(new QLabel("progress: "));
            hor_layout->addWidget(progress_status_label_);
            hor_layout->addStretch(2);
        }
        ver_layout->addLayout(hor_layout);

        ver_layout->addSpacing(10);

        // threads statistics
        for (int i = 0; i != 6; ++i)
        {
            const auto text = QString("thread %1:    %2\% completed")
                .arg(i)
                .arg((i + 1) * 10);
            ver_layout->addWidget(new QLabel(text));
        }

        // for ui flexibility
        ver_layout->addStretch(2);
    }
    setLayout(ver_layout);

    // run |on_progress| every second
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PalindromeWidget::on_progress);
    timer->start(1000);

    setWindowTitle(tr("Palindrome"));
    resize(400, 300);
}

void PalindromeWidget::on_start()
{
    // TODO: process start command
    task_status_label_->setText(QString("started, size = %1, threads = %2")
        .arg(str_len_edit_->text())
        .arg(num_thr_edit_->text()));
}

void PalindromeWidget::on_stop()
{
    // TODO: process stop command
    task_status_label_->setText("stopped");
}

void PalindromeWidget::on_progress()
{
    // TODO: process progress update
    static int calls_count = 0;
    ++calls_count;
    progress_status_label_->setText(QString("call %1").arg(calls_count));
}

void PalindromeWidget::on_dump()
{
    // TODO: dump the latest result
    QMessageBox::warning(this, "dump", "dumping model to a model.txt");
}

