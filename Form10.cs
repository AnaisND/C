using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace PAWProiectFinal
{
    public partial class Form10 : Form
    {
        public Form10()
        {
            InitializeComponent();
            Controls.Add(chart1);
        }

        private void DisplayGanttChart(List<DateTime> beginingDates, List<DateTime> endingDates)
        {
            chart1.Series.Clear();
            chart1.ChartAreas.Clear();

            Series series = new Series("Events");
            ChartArea chartArea = new ChartArea("GanttChart");

            series.ChartType = SeriesChartType.RangeBar;

            for (int i = 0; i < beginingDates.Count; i++)
            {
                DateTime beginingDate = beginingDates[i];
                DateTime endingDate = endingDates[i];

                DataPoint dataPoint = new DataPoint();
                dataPoint.XValue = i + 1;
                dataPoint.AxisLabel = $"Event {i + 1}";
                dataPoint.Color = Color.Blue;
                dataPoint.ToolTip = $"Begin: {beginingDate}\nEnd: {endingDate}";

                double duration = endingDate.Subtract(beginingDate).TotalMinutes;
                dataPoint.YValues = new double[] { duration };

                series.Points.Add(dataPoint);
            }

            chart1.Series.Add(series);
            chart1.ChartAreas.Add(chartArea);

            chart1.ChartAreas[0].AxisX.LabelStyle.Format = "MM/dd/yyyy";
            chart1.ChartAreas[0].AxisX.IntervalType = DateTimeIntervalType.Days;
            chart1.ChartAreas[0].AxisX.Interval = 1;

        }


        private void button1_Click(object sender, EventArgs e)
        {
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "LotFabricatie";
            List<LotFabricatie> Fabricatii = new List<LotFabricatie>();
            var productMongo = new LotFabricatieMongo(connectionString, databaseName, collectionName);
            Fabricatii = productMongo.GetAllFabricatii(connectionString, databaseName, collectionName);
            List<DateTime> DI = new List<DateTime>(); List<DateTime> DT = new List<DateTime>();
            for(int  i = 0; i < Fabricatii.Count; i++)
            {
                DI.Add(Fabricatii[i].DataIncepere);
            }
            for (int i = 0; i < Fabricatii.Count; i++)
            {
                DT.Add(Fabricatii[i].DataTerminare);
            }
            DisplayGanttChart(DI,DT);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
            this.Visible = false;
        }
    }
}
