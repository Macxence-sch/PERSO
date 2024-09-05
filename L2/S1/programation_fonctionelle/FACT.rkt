(define (fact n)
  (if (= n 0) 1 (* n (fact(- n 1)))))

(define (double n) (* n n))

(define (supa a b)
  (and (> a b)))

(define (andor)
  (and (or (< 2 3 ) (< 4 3 )) (> 6 5 )))

(define (fibo n)
  (if (= n 0) 0 (if (= n 1) 1 (+ (fibo (- n 2)) (fibo (- n 1))))))

(define (fibobis n)
 (cond
   ((zero? n) 0)
   ((= n 1) 1)
   (else
    (+ (fibobis (- n 2)) (fibobis(- n 1))))))
       
(define (fibo2 n)
  (if (< n 2) n (+ (fibo2 (- n 2)) (fibo2 (- n 1)))))


(define (pgcd a b)
  (if (zero? b) a
      (pgcd b (modulo a b))))


(define (binaire n)
  (cond
    ((zero? n) 1)
    ((= n 1) 1)
    (else
     (+ 1 (binaire (quotient n 2))))))


(define (boum n)
  (if (zero? n)
      (begin
        (display "0 BOUM !!!!!!!!!!!!!!!!!!!!!!!!")
        (newline))
      (begin
        (display n)
        (display "...")
        (newline)
        (boum (- n 1)))))


(define l '(1 2 3 4 5))

(define (mylength s)
  (if (null? s) 0
      (+ 1 (mylength (cdr s)))))




(define (suite a b)
   (if (= a b) b ((display a )(suite (+ a 1) b))))