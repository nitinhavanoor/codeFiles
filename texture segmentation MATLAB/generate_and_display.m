function generate_and_display(B);

imageout = zeros(450,600);
for i = 1 : (450 * 600)
   
        if(B(i) == 1)
            imageout(i) = 0;
        elseif(B(i) == 2)
            imageout(i) = 102;
        elseif(B(i) == 3)
            imageout(i) = 51;
        elseif(B(i) == 4)
            imageout(i) = 204;
        elseif(B(i) == 5)
            imageout(i) = 153;
        elseif(B(i) == 6)
            imageout(i) = 255;
         
        end
end
figure
imshow(uint8(imageout));