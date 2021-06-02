using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Office.Interop.Excel;
using System.IO;

namespace DataCollector
{
    class Program
    {
        static void Main(string[] args)
        {
            // Создаём экземпляр нашего приложения
            Application excelApp = new Application();
            // Создаём экземпляр рабочий книги Excel
            Workbook workBook;
            // Создаём экземпляр листа Excel
            Worksheet workSheet;

            workBook = excelApp.Workbooks.Add();
            workSheet = (Worksheet)workBook.Worksheets.get_Item(1);

            string path = string.Empty;
            int counterB = 1;
            for (int i = 1; i <= 4; i++)
            {
                int counterI = 1;
                for (int k = 1; k <= 6; k++)
                {
                    path = "selection\\" + i + "\\" + i + "" + 1 + "\\" + "output" + i + "" + 1 + "" + k + ".txt";
                    using (StreamReader sr = new StreamReader(path))
                    {
                        for (int j = 1; j <= 10; j++)
                        {
                            workSheet.Cells[counterI, counterB] = sr.ReadLine();
                            counterI++;
                        }
                        counterI++;
                    }
                }
                counterB++;

                for (int k = 1; k <= 5; k++)
                {
                    path = "selection\\" + i + "\\" + i + "" + 2 + "\\" + "output" + i + "" + 2 + "" + k + ".txt";
                    using (StreamReader sr = new StreamReader(path))
                    {
                        for (int j = 1; j <= 10; j++)
                        {
                            workSheet.Cells[counterI, counterB] = sr.ReadLine();
                            counterI++;
                        }
                        counterI++;
                    }
                }
                counterB++;
            }
            

            excelApp.Application.ActiveWorkbook.SaveAs("selection.xlsx", Type.Missing,
            Type.Missing, Type.Missing, Type.Missing, Type.Missing, XlSaveAsAccessMode.xlNoChange,
            Type.Missing, Type.Missing, Type.Missing, Type.Missing, Type.Missing);
        }
    }
}
