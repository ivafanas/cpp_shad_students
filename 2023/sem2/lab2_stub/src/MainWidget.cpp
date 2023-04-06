#include "MainWidget.h"

#include "TileWidget.h"

#include <QCheckBox>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>

// TODO: refactor MainWidget in order to satisfy software requirement;
//       make sure there is no expensive ops on UI thread

MainWidget::MainWidget()
{
    auto* main_hor_layout = new QHBoxLayout;
    {
        // vertical control panel
        auto* ver_layout = new QVBoxLayout;
        {
            // thread count setting
            auto* hor_layout = new QHBoxLayout;
            {
                hor_layout->addWidget(new QLabel("thread count: "));
                hor_layout->addWidget(thread_count_edit = new QLineEdit);
            }
            ver_layout->addLayout(hor_layout);

            // throttling checkbox
            ver_layout->addWidget(enable_throttling_checkbox = new QCheckBox("enable throttling"));

            // relaunch button
            auto* relaunch_button = new QPushButton("relaunch");
            connect(relaunch_button, &QPushButton::clicked, this, &MainWidget::on_relaunch);
            ver_layout->addWidget(relaunch_button);

            // empty space
            ver_layout->addStretch(2);
        }
        main_hor_layout->addLayout(ver_layout);

        // canvas
        main_hor_layout->addWidget(new TileWidget, /*stretch*/2);
    }
    setLayout(main_hor_layout);

    setWindowTitle(tr("Tiles"));
    resize(600, 450);
}

void MainWidget::on_relaunch()
{
    // TODO: process relaunch event
}

