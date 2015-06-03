namespace hrFlowers
{
    using System;
    using System.Linq;

    class Program
    {
        static void Main()
        {
            var nAndK         = Console.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
            var flowersNeeded = nAndK[0];
            var numFriends    = nAndK[1];
            var flowerCosts   = Console.ReadLine().Split(' ').Select(Int32.Parse).OrderByDescending(x => x).ToArray();
            int flowersBought = 0;
            int moneySpent    = 0;
            int multiplier    = 1;
            for (int i = 0; i < flowersNeeded; ++i)
            {
                moneySpent += flowerCosts[i] * multiplier;
                multiplier = (++flowersBought / numFriends) + 1;
            }
            Console.WriteLine(moneySpent);
        }
    }
}
