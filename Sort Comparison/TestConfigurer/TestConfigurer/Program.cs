using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace TestConfigurer
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = "input";
            //for (int i = 1; i <= 6; i++)
            //{
            //    using (StreamWriter sw = new StreamWriter(path + i + ".txt"))
            //    {
            //        sw.WriteLine(50 * i);
            //        sw.WriteLine(generate(50 * i));
            //        sw.WriteLine();
            //    }
            //}

            for (int i = 0; i <= 4; i++)
            {
                using (StreamWriter sw = new StreamWriter(path + (i + 1) + ".txt"))
                {
                    sw.WriteLine(100 + i * 1000);
                    sw.WriteLine(generate(100 + i * 1000));
                    sw.WriteLine();
                }
            }
        }

        static Random rnd = new Random();
        static string generate(int length)
        {
            string back = string.Empty;
            //for (int i = 0; i < length; i++)
            //{
            //    back += rnd.Next(0, 4001);
            //    back += " ";
            //}

            for (int i = length - 1; i >= 5; i--)
            {
                back += i;
                back += " ";
            }
            for (int i = length - 1; i >= length - 5; i--)
            {
                back += i;
                back += " ";
            }

            //for (int i = 0; i < length - 5; i++)
            //{
            //    back += i;
            //    back += " ";
            //}
            //for (int i = 0; i < 5; i++)
            //{
            //    back += i;
            //    back += " ";
            //}
            return back;
        }
    }
}
