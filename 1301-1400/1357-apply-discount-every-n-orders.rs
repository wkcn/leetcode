use std::collections::HashMap;

struct Cashier {
    n: i32,
    discount: i32,
    product2price: HashMap<i32, i32>,
    cnt: i32,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Cashier {

    fn new(n: i32, discount: i32, products: Vec<i32>, prices: Vec<i32>) -> Self {
        let product2price: HashMap<i32, i32> = products.iter().zip(prices.iter()).map(|x| (*x.0, *x.1)).collect(); 
        Cashier {
            n: n,
            discount: discount,
            product2price: product2price,
            cnt: 0,
        }
    }
    
    fn get_bill(&mut self, product: Vec<i32>, amount: Vec<i32>) -> f64 {
        /*
        let cost = product.iter().zip(amount.iter()).fold(0_i64, |acc, x| {
            acc + (self.product2price[x.0] * (*x.1)) as i64
        });
        */
        let cost: i64 = product.iter().zip(amount.iter()).map(|x| (self.product2price[x.0] * (*x.1)) as i64).sum();
        self.cnt += 1;
        if self.cnt % self.n == 0 {
            return cost as f64 - (self.discount as i64 * cost) as f64 / 100.0;
        }
        cost as f64
    }
}

fn main() {
    let n = 3; 
    let discount = 50;
    let products = vec![1,2,3,4,5,6,7];
    let prices = vec![100, 200, 300, 400, 300, 200, 100];
    let mut cashier = Cashier::new(n, discount, products, prices);
    assert_eq!(cashier.get_bill(vec![1,2],vec![1,2]), 500.0);
    assert_eq!(cashier.get_bill(vec![3,7],vec![10,10]), 4000.0);
    assert_eq!(cashier.get_bill(vec![1,2,3,4,5,6,7],vec![1,1,1,1,1,1,1]), 800.0);
}
