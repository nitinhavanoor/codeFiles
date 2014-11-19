function A = filter_image(f1,B);

A = zeros(450,600);

sum = 0.0;
for i = 2 : 451
    for j = 2 : 601
        sum = 0.0;
        for i1 = -1 : 1
            for j1 = -1 : 1
                
                sum = sum + (f1(i1+2,j1+2) * B(i+i1,j+j1));
            end
        end
        A(i-1,j-1) = sum;
        
    end
end

