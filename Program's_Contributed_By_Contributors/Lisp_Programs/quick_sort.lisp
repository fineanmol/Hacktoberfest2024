(setf my-array (make-array '(10)
	  :initial-contents '(10 9 8 7 6 5 4 3 2 1)))

; swap
(defun swap (i j)
  (setf temp (aref my-array i))
  (setf (aref my-array i) (aref my-array j))
  (setf (aref my-array j) temp))

(defun partition (left right)
  (setq pivot (aref my-array left))
  ;find the pivot index
  (setq pivot_index 0)
  (setq i left)

  ; count how many numbers is <= pivot
  (dotimes (k (+ (- right left) 1))
	(if (<= (aref my-array (+ left k)) pivot)
	  (setq pivot_index (+ pivot_index 1))))

  (setq pivot_index (- pivot_index 1))
  (setq pivot_index (+ pivot_index left))

  (swap left pivot_index)

  ;move the numbers
  (setq i left)
  (setq j right)
  

  (loop
	while (and (< i pivot_index ) (> j pivot_index))
	do (progn 
		 (format t "i = ~d j = ~d pivot_index = ~d~%" i j pivot_index)
		 (loop
		   while (and (<= i right) (<= (aref my-array i) pivot))
		   do (setq i (+ i 1)))
		 (loop
		   while (and (>= j left) (> (aref my-array j) pivot))
		   do (setq j (- j 1)))
		 (if (and (< i pivot_index)
				  (> j pivot_index)
				  (>= j left)
				  (<= i right))
		   (progn
			 (swap i j)))))

  pivot_index)

(defun quick_sort (left right)
  (if (>= left right)
	nil
	(progn
	  (setq p (partition left right))
	  (quick_sort left (- p 1))
	  (quick_sort (+ p 1) right))))

(defun print_array ()
  (dotimes (i 10)
	(write (aref my-array i))
	(format t " "))
  (format t "~%"))

(print_array)
(quick_sort 0 9)
(print_array)
